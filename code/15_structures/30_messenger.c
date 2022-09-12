#include <string.h>
#include <stdio.h>

struct Message
{
    int sender_id;
    int receiver_id;
    char content[256];
};

struct Message receive_message(int my_id)
{
    struct Message result;

    result.sender_id = 32;
    result.receiver_id = my_id;
    strcpy(result.content, "1 message from your pal");

    return result;
}

int main( void )
{
    struct Message simulated_msg = receive_message(10);

    printf(
        "from: %i\nto: %i\n\n%s\n",
        simulated_msg.sender_id,
        simulated_msg.receiver_id,
        simulated_msg.content);
}