#ifndef STRING
#define STRING

class String
{
private:
    char *str;
    int size;

public:
    String(int size);
    ~String();

    int find_strlen();
    void set_string();
    void display_string();
};

#endif