// Question 1 Install g tests and add to cmakes lists
#include "gtest/gtest.h"
#include <iostream>
#include <map>
#include <cmath>
#include <thread>
#include <mutex>

const int values[] = { 1,2,3,4,5 };
const int NVALS = sizeof values / sizeof (int);
void function(char**);

template <typename T>
struct ptr_holder {
  static_assert(!std::is_same<T, std::remove_pointer<T>>::value);
};

int total = 0;
class Wallet
{
    int mMoney;
    std::mutex money_lock;
public:
    Wallet() :mMoney(0){}
    int getMoney() { return mMoney; }
    void addMoney(int money)
    {
       for(int i = 0; i < money; ++i)
       {
          money_lock.lock();
          mMoney++;
          money_lock.unlock();
       }
    }
};

struct {
   int age;
   float weight;
} person;

// gtest
TEST(WalletTest, HandlesThreads) {
    Wallet walletObject;
    std::vector<std::thread> threads;
    for(int i = 0; i < 5; ++i){
            threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 1000));
    }
    for(int i = 0; i < threads.size() ; i++)
    {
        threads.at(i).join();
    }
    int val = 0;
    for(int k = 0; k < 1000; k++)
    {
        EXPECT_EQ(val = walletObject.getMoney(), 5000);
    }
}

int main()
{
    // Question 2
    int x = 10;
    int y = 15;
    std::cout << x << " " << y << std::endl;

    // Question 3 Get the function to run
    char *arr[] = { "ant", "bat", "cat", "dog", "egg", "fly" };
	function(arr);


    // Question 4 Insert in map
    typedef std::map<int, double> valmap;

    valmap m;

    for (int i = 0; i < NVALS; i++)
        m.insert(std::make_pair(values[i], pow(values[i], .5)));

    // valmap::iterator it = 100;              
    // valmap::iterator it2(100);              
    valmap::iterator it;
    valmap::iterator it2;
    m.insert(std::make_pair(1,2.0));
    
    // Question 5
    int i = 1, j = 1;
    if ( (i != 3) && (j==1))
    {
        std::cout << "inside if statement\n";
    }

    // Question 6 Store a char * pointer in template
    ptr_holder<char *> p;

    // Question 7 Fix the compiler errors and race conditions
    // testerFunction() moved to google test before main
    

    // // Question 8
    // int n = 1;
    // int *p = &n;
    // fn(&p);

    // // Question 9
    // struct person *ptr;
    // ptr = (struct person*)malloc(sizeof(struct person));
    // ptr->age = 10;
    // ptr->weight = 55.5;

    // // Question 10 Initialise foo
    // Foo foo;

    // // Question 11
    // char c;
    // while(c = getchar() == EOF)
    // {
    //     putchar(c);
    // }

    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();

}

// Do not change anything besides the ptr variable
void function(char **ptr)
{
	char *ptr1;
	ptr1 = (ptr += sizeof(int))[-2];
	printf("%s\n", ptr1);
}
void fn(const int** pp)
{
    printf("%p : %p : %d", pp, *pp, **pp);
}

// Fix any compilation error
class Foo {
public:
    Foo(int a, Wallet* b = NULL);
};