#include <cs50.h>
#include <stdio.h>
#include <string.h>

int type_check(long num);
int luhn_check(long num);
int type = 0;

int main(void)
{

    long card = get_long("Number: ");

    type = type_check(card);

    if (luhn_check(card) == 0)
    {
        if (type == 1)
        {
            printf("AMEX\n");
        }
        else if (type == 2)
        {
            printf("MASTERCARD\n");
        }
        else if (type == 3)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int type_check(long num)
{

    // RETURN TYPES:
    // 0 - INVALID
    // 1 - AMEX
    // 2 - MASTERCARD
    // 3 - VISA

    if (num > 4000000000000 && num <= 4999999999999)
    {
        return 3;
    }
    else if (num >= 340000000000000 && num <= 349999999999999)
    {
        return 1;
    }
    else if (num >= 370000000000000 && num <= 379999999999999)
    {
        return 1;
    }
    else if (num >= 4000000000000000 && num <= 4999999999999999)
    {
        return 3;
    }
    else if (num >= 5100000000000000 && num <= 5599999999999999)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int luhn_check(long num)
{

    long n = num;
    int length = 0;
    int checksum_a = 0;
    int sum_b = 0;
    int sum_a = 0;

    while (n != 0)
    {
        n = n / 10;
        length++;
    }

    int numbers[length] = {};

    // SOLVING CHECKSUMS

    if (length % 2 == 1)
    {
        for (int i = 0; i < length / 2 + 1; i++)
        {
            sum_b += num % 10;
            num = num / 10;
            int doubled = (num % 10) * 2;
            sum_a += (doubled / 10) + (doubled % 10);
            num = num / 10;
        }
    }
    else
    {
        for (int i = 0; i < length / 2; i++)
        {
            sum_b += num % 10;
            num = num / 10;
            int doubled = (num % 10) * 2;
            sum_a += (doubled / 10) + (doubled % 10);
            num = num / 10;
        }
    }

    // ADDING THE VALUES TOGETHER FROM CHECKSUM_A

    if (length % 2 == 1)
    {
        for (int j = 0; j < length / 2 + 1; j++)
        {
            sum_a += checksum_a % 10;
            checksum_a = checksum_a / 10;
        }
    }
    else
    {
        for (int j = 0; j < length / 2; j++)
        {
            sum_a += checksum_a % 10;
            checksum_a = checksum_a / 10;
        }
    }

    if ((sum_a + sum_b) % 10 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
