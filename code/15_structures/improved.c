#include <string.h>
#include <stdio.h>

typedef unsigned int user_id;

typedef struct Message
{
    user_id sender_id;
    user_id receiver_id;
    char content[256];
} Message ;

Message receive_message(int my_id)
{
    Message result;

    result.sender_id = 32;
    result.receiver_id = my_id;
    strcpy(result.content, "1 message from your pal");

    return result;
}

int main( void )
{
    Message simulated_msg = receive_message(10);

    printf(
        "from: %i\nto: %i\n\n%s\n",
        simulated_msg.sender_id,
        simulated_msg.receiver_id,
        simulated_msg.content);
}