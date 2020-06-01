const char *myStrStr(const char *source, const char *to_find)
{
    const char *ret_val = 0;

    if (source == 0 || to_find == 0 || sizeof(source) < sizeof(to_find))
    {
        return ret_val;
    }

    /*
        s = "abcdefastrxyz"; "aastr"
        f = "astr";
    */
    const char *backup_to_find = to_find;
    while (*source != 0) //Checking for end of string
    {
        if (*source != *to_find)
        {
            to_find = backup_to_find;
            ret_val = 0;
        }

        if (*source == *to_find)
        {
            if (ret_val == 0)
            {
                ret_val = source;
            }
            to_find++;
            if (*to_find == 0)
            {
                break;
            }
        }
        source++;
    }

    return (*to_find != 0) ? 0 : ret_val;
}

// 1, 2, 3, 4, 5, 6
void ReArrange(int *ptr, int pos)
{
    int numOfEntries = sizeof(ptr) / sizeof(int *);

    if (ptr == 0 || pos >= numOfEntries)
    {
        return;
    }

    int *startPtr = ptr;

    ptr = (ptr + pos * sizeof(int *));
    int val = *ptr;
    while (pos > 0)
    {
        *ptr = *(ptr - 1 * sizeof(int *));
        ptr--;
        pos--;
    }

    *startPtr = val;
}