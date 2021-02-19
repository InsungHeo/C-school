int regcd(int a, int b);
int legcd(int a, int b);

int regcd(int a, int b)
{
    if (a == b)
        return a;
    else if (a == 0)
        return b;
    else if (b == 0)
        return a;
    else
        return regcd(a%b, b%a);

}

int legcd(int a, int b)
{
    int l;
    if (a == b)
        return a;
    while (a*b != 0)
    {
        l = a;
        a = a%b;
        b = b%l;
    }

    if (a == 0)
        return b;
    if (b == 0)
        return a;

}
