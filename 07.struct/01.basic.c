
int main(void)
{
    struct Person
    {
        char *name;
        int age;
        char *id;
    };

    // 结构体初始化
    struct Person person = {.name = "benjamin", .age = 18, .id = 'a'};
    printf("person.age: %d\n", person.age);
    struct Person *person_ptr = &person;

    // 结构体指针变量 访问成员变量需要用 ->
    printf("person_ptr->age: %d\n", person_ptr->age);

    // 匿名结构体
    struct
    {
        char *name;
        int age;
        char *id;
    } anonymous_person;

    // 这样定义的结构体，可以直接使用 NewPerson 作为类型名
    typedef struct NewPerson
    {
        char *name;
        int age
    } NewPerson;

    NewPerson new_person = {.age = 19, .name = "file"};

    return 0;
}