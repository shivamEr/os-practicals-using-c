#include <stdio.h>
void main()
{
  int buffer[10], buffer_size, in, out, producer, consumer;
  int choice = 0;
  out = 0;
  in = 0;
  buffer_size = 10;
  while (choice != 3)
  {
    printf("\nEnter 1.Producer\t2.Consumer\t3.Exit");
    printf("\nEnter your choice :");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      if (in + 1 % buffer_size == out)
      {
        printf("\nBuffer is full");
      }
      else
      {
        printf("\nEnter the value for produce : ");
        scanf("%d", &producer);
        buffer[in] = producer;
        in = (in + 1) % buffer_size;
      }
      break;
    case 2:
      if (in == out)
      {
        printf("\nBuffer is empty");
      }

      else
      {
        consumer = buffer[out];

        printf("\nThe consumed value is %d", consumer);
        out = (out + 1) % buffer_size;
      }
      break;
    }
  }
}