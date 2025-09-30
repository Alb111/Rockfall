#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include "../lib/chan/chan.h"

chan_t* chan;

void* ping()
{
    // Send blocks until receiver is ready.
    chan_send(chan, "ping\n");
    chan_send(chan, "lol\n");
    return NULL;
}

int main()
{
    // Initialize unbuffered channel.
    chan = chan_init(3);

    pthread_t th;
    pthread_create(&th, NULL, ping, NULL);

    // Receive blocks until sender is ready.
    void* msg;
    int count = 0;
    while ( count < 2 )
    {
        chan_recv(chan, &msg);
        char* x = (char*)msg;   
        printf("%s\n", x);
        count ++;
    }
    pthread_join(th, NULL);
    chan_close(chan);
    // Clean up channel.
    chan_dispose(chan);
}