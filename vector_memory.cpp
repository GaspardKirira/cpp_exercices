// Matrix 2D allocation dynamique

// #include <iostream>

// int main()
// {
//     int row = 3;
//     int cols = 4;

//     int **matrix = new int *[row];

//     for (int i = 0; i < row; i++)
//     {
//         matrix[i] = new int[cols];
//     }

//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             matrix[i][j] = (i + 1) * (j + 1);
//         }
//     }

//     std::cout << "Matrix 2D" << std::endl;
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             std::cout << matrix[i][j] << ",";
//         }
//         std::cout << std::endl;
//     }

//     for (int i = 0; i < row; i++)
//     {
//         delete[] matrix[i];
//     }

//     delete[] matrix;

//     return 0;
// }

// 3. Benchmark : Construction vs déplacement d'objets
// #include <iostream>
// #include <vector>
// #include <chrono>

// class MyClass
// {
// public:
//     MyClass(int value)
//         : m_value(value) { std::cout << "Constructor" << std::endl; }
//     MyClass(const MyClass &rhs)
//         : m_value(rhs.m_value) { std::cout << "Copy constructor" << std::endl; }
//     MyClass(MyClass &&rhs) noexcept
//         : m_value(rhs.m_value) { std::cout << "Move constructor" << std::endl; }
//     ~MyClass() {}

// private:
//     int m_value{};
// };

// int main()
// {
//     const int N = 100'000;

//     std::vector<MyClass> v1;
//     auto start1 = std::chrono::high_resolution_clock::now();
//     for (int i = 0; i < N; i++)
//     {
//         MyClass obj(i);
//         v1.push_back(obj);
//     }
//     auto end1 = std::chrono::high_resolution_clock::now();

//     std::cout << "Time v1: " << std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count() << " ms" << std::endl;

//     // 1348 ms

//     std::vector<MyClass> v2;
//     auto start2 = std::chrono::high_resolution_clock::now();
//     for (int i = 0; i < N; i++)
//     {
//         MyClass obj(i);
//         v2.emplace_back(obj);
//     }
//     auto end2 = std::chrono::high_resolution_clock::now();

//     std::cout << "Time v2: " << std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count() << " ms" << std::endl;
//     // 1283 ms

//     return 0;
// }

// 4. Benchmark : Comparaison avec des conteneurs alternatifs
// #include <iostream>
// #include <chrono>
// #include <deque>
// #include <vector>

// int main()
// {
//     const int N = 1'000'000;

//     std::vector<int> v;
//     auto start1 = std::chrono::high_resolution_clock::now();
//     for (int i = 0; i < N; i++)
//     {
//         v.push_back(i);
//     }
//     auto end1 = std::chrono::high_resolution_clock::now();

//     std::cout << "Time vector: " << std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count() << " ms" << std::endl;

//     std::deque<int> d;
//     auto start2 = std::chrono::high_resolution_clock::now();
//     for (int i = 0; i < N; i++)
//     {
//         d.push_back(i);
//     }
//     auto end2 = std::chrono::high_resolution_clock::now();

//     std::cout << "Time deque: " << std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count() << " ms" << std::endl;

//     return 0;
// }

// 5. Benchmark : Effet de la mémoire sur les grandes structures
#include <iostream>
#include <vector>
#include <chrono>
#include <memory>

class MyClass
{
public:
    MyClass(int value)
        : m_value(value) {};
    MyClass(const MyClass &rhs)
        : m_value(rhs.m_value) {}
    MyClass(MyClass &&rhs) noexcept
        : m_value(rhs.m_value) {}

private:
    int m_value{};
};

// class MyClass
// {
//     int data[1000];
// };

int main()
{
    const int N = 1'000'000;

    auto start1 = std::chrono::high_resolution_clock::now();
    std::vector<MyClass> v1;
    v1.reserve(N);
    for (int i = 0; i < N; i++)
    {
        v1.emplace_back(MyClass(i));
    }
    auto end1 = std::chrono::high_resolution_clock::now();

    std::cout << "Time v1 sans data: " << std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count() << " ms" << std::endl;

    std::vector<std::unique_ptr<MyClass>> v2;
    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++)
    {
        v2.push_back(std::make_unique<MyClass>(i));
    }
    auto end2 = std::chrono::high_resolution_clock::now();

    std::cout << "Time v2 sans data: " << std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count() << " ms" << std::endl;
}