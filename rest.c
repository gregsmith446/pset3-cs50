// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (!s) //if a line in the string is an empty new line (aka a rest)
    {
        return true;
    }
    return false;
}

int main(void)
{
   is_rest();
}