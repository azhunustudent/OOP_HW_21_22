#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;


/*
  Перегрузка операторов

    CatDog = Cat + Dog
    ? = Dog + Cat

*/

// Прототипы классов
class Cat;
class Dog;
class CatDog;
class DogCat;


// Для классов Cat, Dog, CatDog, DogCat задайте переменные:
// -Имя животного,
// -Порода, 
// -Возраст
// Для класса Cat дополнительно задайте переменную, характерную для такого класса,
// например, кол - во прочтенных книг(по мультфильму) или пойманных мышей.
// Для класса Dog дополнительно задайте переменную, характерную для этого класса,
// например, кол - во програнных почтальоннов(по мультфильму) или кол - во сгрызенных косточек.
// Тогда для классов CatDog, DogCat задайте такие же дополнительные переменные, что будут и Cat и Dog.

// Для этих классов написать перегруженный оператор '+', чтобы можно было выполнить
// операцию сложения классов Cat и Dog и получить класс CatDog:
// class CatDog = class Cat + class Dog;
// и операцию сложения классов Dog и Cat и получить класс DogCat:
// class DogCat = class Dog + class Cat; -доделать

class Cat
{
private:
    string Name;
    string Breed;
    int Age;
    int BooksCount;
public:
    Cat() : Name("Неизвестно"), Breed("Неизвестно"), Age(), BooksCount() {}
    Cat(string name, string breed, int age, int booksCount) : Name(name), Breed(breed), Age(age), BooksCount(booksCount) {}

    // геттеры-сеттеры
    void SetName(string name) { Name = name; }
    void SetBreed(string breed) { Breed = breed; }
    void SetAge(int val) { Age = val; }
    void SetBooksCount(int val) { BooksCount = val; }

    string GetName()const { return Name; }
    string GetBreed()const { return Breed; }
    int GetAge()const { return Age; }
    int GetBooksCount()const { return BooksCount; }

    // операторы ввода - вывода: << , >>
    friend ostream& operator<< (ostream& os, const Cat& obj)
    {
        os << typeid(obj).name() << endl;
        os << "Имя: " << obj.GetName()
           << "\nПорода: " << obj.GetBreed()
           << "\nВозраст: " << obj.GetAge()
           << "\nКол-во прочитанных книг: " << obj.GetBooksCount();
        return os;
    }

    friend istream& operator>>(istream& is, Cat& obj)
    {
        cout << typeid(obj).name() << ":" << endl;

        string t1;
        int t2;
        
        cout << "Введите имя: ";
        is >> t1;
        obj.SetName(t1);

        cout << "Введите породу: ";
        is >> t1;
        obj.SetBreed(t1);

        cout << "Введите возраст: ";
        (is >> t2).ignore();
        obj.SetAge(t2);

        cout << "Введите кол-во прочитанных книг: ";
        (is >> t2).ignore();
        obj.SetBooksCount(t2);

        return is;
    }

    friend CatDog operator+(const Cat& cat, const Dog& dog);
    friend DogCat operator+(const Dog& dog, const Cat& cat);
};


class Dog
{
private:
    string Name;
    string Breed;
    int Age;
    int BonesCount;
public:
    Dog() : Name("Неизвестно"), Breed("Неизвестно"), Age(), BonesCount() {}
    Dog(string name, string breed, int age, int bonesCount) : Name(name), Breed(breed), Age(age), BonesCount(bonesCount) {}

     
    // геттеры-сеттеры
    void SetName(string name) { Name = name; }
    void SetBreed(string breed) { Breed = breed; }
    void SetAge(int val) { Age = val; }
    void SetBonesCount(int val) { BonesCount = val; }

    string GetName()const { return Name; }
    string GetBreed()const { return Breed; }
    int GetAge()const { return Age; }
    int GetBonesCount()const { return BonesCount; }

    // операторы ввода - вывода: << , >>
    friend ostream& operator<< (ostream& os, const Dog& obj)
    {
        os << typeid(obj).name() << endl;
        os << "Имя: " << obj.GetName()
            << "\nПорода: " << obj.GetBreed()
            << "\nВозраст: " << obj.GetAge()
            << "\nКол-во сгрызанных косточек: " << obj.GetBonesCount();
        return os;
    }

    friend istream& operator>>(istream& is, Dog& obj)
    {
        cout << typeid(obj).name() << ":" << endl;

        string t1;
        int t2;
        cout << "Введите имя: ";
        is >> t1;
        obj.SetName(t1);

        cout << "Введите породу: ";
        is >> t1;
        obj.SetBreed(t1);

        cout << "Введите возраст: ";
        (is >> t2).ignore();
        obj.SetAge(t2);
        
        cout << "Введите кол-во сгрызанных косточек: ";
        (is >> t2).ignore();
        obj.SetBonesCount(t2);

        return is;
    }

    friend CatDog operator+(const Cat& cat, const Dog& dog);
    friend DogCat operator+(const Dog& dog, const Cat& cat);
};


class CatDog
{
private:
    string Name;
    string Breed;
    int Age;
    int BooksCount;
    int BonesCount;
public:
    CatDog() : Name("Неизвестно"), Breed("Неизвестно"), Age(), BooksCount(), BonesCount() {}
    CatDog(string name, string breed, int age, int books, int bones) :
        Name(name), Breed(breed), Age(age), BooksCount(books), BonesCount(bones) {}

    void SetName(string name) { Name = name; }
    void SetBreed(string breed) { Breed = breed; }
    void SetAge(int val) { Age = val; }
    void SetBonesCount(int val) { BonesCount = val; }
    void SetBooksCount(int val) { BooksCount = val; }

    string GetName()const { return Name; }
    string GetBreed()const { return Breed; }
    int GetAge()const { return Age; }
    int GetBonesCount()const { return BonesCount; }
    int GetBooksCount()const { return BooksCount; }

    friend ostream& operator<< (ostream& os, const CatDog& obj)
    {
        os << typeid(obj).name() << endl;
        os << "Имя: " << obj.GetName()
            << "\nПорода: " << obj.GetBreed()
            << "\nВозраст: " << obj.GetAge()
            << "\nКол-во прочитанных книг котом: " << obj.GetBooksCount()
            << "\nКол-во сгрызанных косточек у собаки: " << obj.GetBonesCount();
        return os;
    }

    friend CatDog operator+(const Cat& cat, const Dog& dog);
};


class DogCat
{
private:
    string Name;
    string Breed;
    int Age;
    int BooksCount;
    int BonesCount;
public:
    DogCat() : Name("Неизвестно"), Breed("Неизвестно"), Age(), BooksCount(), BonesCount() {}
    DogCat(string name, string breed, int age, int books, int bones) : 
        Name(name), Breed(breed), Age(age), BooksCount(books), BonesCount(bones) {}

    void SetName(string name) { Name = name; }
    void SetBreed(string breed) { Breed = breed; }
    void SetAge(int val) { Age = val; }
    void SetBonesCount(int val) { BonesCount = val; }
    void SetBooksCount(int val) { BooksCount = val; }

    string GetName()const { return Name; }
    string GetBreed()const { return Breed; }
    int GetAge()const { return Age; }
    int GetBonesCount()const { return BonesCount; }
    int GetBooksCount()const { return BooksCount; }

    friend ostream& operator<< (ostream& os, const DogCat& obj)
    {
        os << typeid(obj).name() << endl;
        os << "Имя: " << obj.GetName()
            << "\nПорода: " << obj.GetBreed()
            << "\nВозраст: " << obj.GetAge()
            << "\nКол-во сгрызанных косточек у собаки: " << obj.GetBonesCount()
            << "\nКол-во прочитанных книг котом: " << obj.GetBooksCount();
        return os;
    }

    friend DogCat operator+(const Dog& dog, const Cat& cat);
};

CatDog operator+(const Cat& cat, const Dog& dog)
{
    CatDog res;
    res.SetName(cat.GetName() + "-" + dog.GetName());
    res.SetBreed(cat.GetBreed() + "-" + dog.GetBreed());
    res.SetAge(cat.GetAge() + dog.GetAge());
    res.SetBooksCount(cat.GetBooksCount());
    res.SetBonesCount(dog.GetBonesCount());
    return res;
}

DogCat operator+(const Dog& dog, const Cat& cat)
{
    DogCat res;
    res.SetName(dog.GetName() + "-" + cat.GetName());
    res.SetBreed(dog.GetBreed() + "-" + cat.GetBreed());
    res.SetAge(dog.GetAge() + cat.GetAge());
    res.SetBonesCount(dog.GetBonesCount());
    res.SetBooksCount(cat.GetBooksCount());
    return res;
}

int main()
{
    Dog dog;
    Cat cat;

    cin >> cat;
    cout << "--------------------------------------------------\n";
    cin >> dog;

    CatDog CD = cat + dog;

    cout << "--------------------------------------------------\n";
    cout << cat << endl;

    cout << "--------------------------------------------------\n";
    cout << dog << endl;

    cout << "--------------------------------------------------\n";
    cout << CD << endl;

    cout << "--------------------------------------------------\n";
    DogCat DC = dog + cat;
    cout << DC << endl;
}