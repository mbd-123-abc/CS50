#include <stdio.h>

int chooseVersion(void);
int chooseHeight(void);
void pyramid(int height, int version);

int main(void)
{
    int version = chooseVersion();
    int height = chooseHeight();

    pyramid(height, version);
}

int chooseVersion(void)
{
    int version;

    do
    {
        printf("Version: ");
        scanf("%i", &version);
    }
    while(version != 1 && version != 2);

    return version;
}

int chooseHeight(void)
{
    int height;

    do
    {
        printf("Pyramid Height: ");
        scanf("%i", &height);
    }
    while(height < 0);

    return height;
}

void pyramid(int height, int version)
{
    for(int i = 1; i <= height; i++)
    {
        if (version == 2)
        {
            for(int j = 0; j < height-i; j++)
            {
                printf(" ");
            }

            for(int j = 0; j < i; j++)
            {
                printf("#");
            }

            printf("  ");
        }

        for(int j = 0; j < i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}
