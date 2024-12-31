
// Exercice 1 (correction Pointer dangling)
// #include <iostream>

// int *func()
// {
//     int *x = new int(10);
//     return x;
// }

// int main()
// {
//     int *ptr = func();
//     if (ptr != nullptr)
//     {
//         std::cout << "Ptr: " << *ptr << std::endl;
//     }
//      delete ptr;

//     return 0;
// }

// Excercice 2 (correction Reference dangling)
// #include <iostream>

// int &func2()
// {
//     int *x = new int(20);
//     return *x;
// }

// int main()
// {
//     int *ptr = &func2();

//     if (ptr != nullptr)
//     {
//         std::cout << "Ptr: " << *ptr << std::endl;
//     }

//     delete ptr;

//     return 0;
// }

// Exercice 3 (correction Allocation et liberation de memoire)

// #include <iostream>

// int main()
// {
//     int *ptr = new int(20);
//     delete ptr;
//     ptr = nullptr;
//     if (ptr != nullptr)
//     {
//         std::cout << "x is: " << *ptr << std::endl;
//     }
//     else
//     {
//         std::cout << "ptr is nullptr, memory has been freed." << std::endl;
//     }

//     return 0;
// }

// Exercice 4 (correction Double suppression)

// #include <iostream>

// int main()
// {
//     int *ptr = new int(42);
//     delete ptr;
//     ptr = nullptr;

//     delete ptr;

//     return 0;
// }

// Exercice 5 (correction validation des pointers)
// #include <iostream>

// int main()
// {
//     int *ptr = nullptr;

//     if (ptr != nullptr)
//     {
//         std::cout << "ptr is valid, value: " << *ptr << std::endl;
//     }
//     else
//     {
//         std::cout << "ptr is nullptr, cannot dereference." << std::endl;
//     }

//     delete ptr;

//     return 0;
// }

// Exercice 6 (correction Smart pointer)
// #include <iostream>
// #include <memory>

// int main()
// {
//     std::unique_ptr<int> ptr = std::make_unique<int>(20);

//     if (ptr != nullptr)
//     {
//         std::cout << "ptr is valid, value: " << *ptr << "\n";
//     }
//     else
//     {
//         std::cout << "ptr is not valid" << "\n";
//     }

//     return 0;
// }

// Exercice 7 (correction Stack Overflow)
// #include <iostream>

// int func(int n)
// {
//     return n * func(n - 1);
// }

// int main()
// {
//     std::cout << func(4) << std::endl;

//     return 0;
// }

// Exercice 9 (correction Fragmentation Mémoire)

// #include <iostream>

// int main()
// {
//     const int n = 10;
//     int *ptr = new int[n];

//     for (int i = 0; i < n; i++)
//     {
//         ptr[i] = i + 1;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         std::cout << "ptr[" << i << "]" << std::endl;
//     }

//     delete[] ptr;

//     return 0;
// }

// Exercice 9 (correction Pointeur et Tableau)

// #include <iostream>

// int main()
// {
//     const int n = 5;
//     int *ptr = new int[n];

//     for (int i = 0; i < n; i++)
//     {
//         ptr[i] = i + 1;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         std::cout << "ptr[" << i << "]" << std::endl;
//     }

//     delete[] ptr;

//     return 0;
// }

// Exercice 10 : Manipulation de Pointeurs
// #include <iostream>

// int main()
// {
//     const int n = 5;
//     int array[n];

//     for (int i = 0; i < n; i++)
//     {
//         array[i] = i + 1;
//     }

//     int *ptr = array;
//     std::cout << *ptr << std::endl;
//     std::cout << *(ptr + 1) << std::endl;
//     std::cout << *(ptr + 2) << std::endl;
//     std::cout << *(ptr + 3) << std::endl;
//     std::cout << *(ptr + 4) << std::endl;

//     return 0;
// }

// Exercice 11 : Double Pointeurs
// #include <iostream>

// int main()
// {
//     int *ptr = new int(42);

//     int **x = &ptr;

//     **x = 39;

//     std::cout << "x is: " << **x << std::endl;

//     return 0;
// }

// // Exercice 12 : (Correction Différence entre Pile et Tas)
// #include <iostream>

// int main()
// {
//     int x = 29;
//     int *ptr = new int(42);

//     std::cout << "x is: " << &x << std::endl;
//     std::cout << "ptr is: " << ptr << std::endl;

//     // Explication des adresses :
//     // Les deux adresses sont différentes car :
//     // - "x" est stocké sur la pile, une mémoire temporaire gérée automatiquement par le programme.
//     // - "*ptr" (la valeur pointée par ptr) est stockée sur le tas, une mémoire dynamique qui doit être allouée manuellement et libérée par le programme.

//     delete ptr;

//     return 0;
// }

// Exercice 13 : (Correction Gestion de Mémoire Dynamique pour une Structure)
// #include <iostream>
// #include <string>

// struct Person
// {
//     std::string name{};
//     int age{};
// };

// int main()
// {
//     Person *p = new Person();
//     p->name = "Gaspard";
//     p->age = 23;

//     std::cout << "Name: " << p->name << std::endl;
//     std::cout << "Age: " << p->age << std::endl;

//     delete p;

//     return 0;
// }

// Exercice 14 : (Correction Pointer vers une Fonction)

// #include <iostream>

// int square(int x)
// {
//     return x * x;
// }

// int double_value(int x)
// {
//     return x * x;
// }

// int main()
// {
//     int (*func_ptr)(int);

//     func_ptr = double_value;
//     std::cout << "Result: " << func_ptr(10) << std::endl;

//     std::cout << "***********************" << std::endl;

//     func_ptr = square;
//     std::cout << "Result: " << func_ptr(4) << std::endl;

//     return 0;
// }

// Exercice 15 : Utilisation de const avec les Pointeurs

// #include <iostream>

// int main()
// {
//     const int *ptr = new int(42);
//     std::cout << "ptr is: " << *ptr << std::endl;
//     std::cout << "Adress of const ptr is: " << ptr << "\n";

//     const int x = 30;
//     const int *ptr2 = &x;
//     std::cout << "const ptr2 is: " << *ptr2 << std::endl;
//     std::cout << "Adress of const ptr2 is: " << ptr2 << "\n";

//     return 0;
// }

// Exercice 16 : Allocation Dynamique d'un Matrice 2D
// #include <iostream>

// int main()
// {
//     int row = 3;
//     int cols = 4;

//     // Alloue dynamiquement une matrix 2D(tableau des pointers)
//     int **matrix = new int *[row];

//     // Allouer chaque ligne de la matrix
//     for (int i = 0; i < row; i++)
//     {
//         matrix[i] = new int[cols];
//     }

//     // Assigner des valeurs a chaque element de la matrix
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             matrix[i][j] = (i + 1) * (j + 1);
//         }
//     }

//     // Afficher la matrix 2D
//     std::cout << "Matrix 2D" << std::endl;
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             std::cout << matrix[i][j] << ",";
//         }
//         std::cout << std::endl;
//     }

//     // Liberer de la memoire
//     for (int i = 0; i < row; i++)
//     {
//         // Liberer chaque ligne(tableau d'entiers)
//         delete[] matrix[i];
//     }

//     delete[] matrix;

//     return 0;
// }

// Exercice 17 : Éviter les Conversions de Types Inappropriées
// #include <iostream>

// int main()
// {
//     int x = 42;
//     void *ptr = &x;

//     int *f_ptr = (int *)ptr;

//     std::cout << "f_ptr: " << *f_ptr << std::endl;
// }

// Exercice 18 : Gestion avec std::shared_ptr
// #include <iostream>
// #include <memory>

// class Test
// {
// public:
//     Test() { std::cout << "Constructor" << std::endl; }
//     ~Test() { std::cout << "Destructor" << std::endl; }
//     void afficher() { std::cout << "test cool!" << std::endl; }
// };

// int main()
// {
//     std::shared_ptr<Test> ptr = std::make_shared<Test>();
//     {
//         std::shared_ptr<Test> ptr2 = ptr;
//         std::cout << "ptr2 est dans une portée locale." << std::endl;
//         ptr2->afficher();
//     }
//     std::cout << "ptr2 a quitté la portée." << std::endl;
//     std::cout << "ptr1 est toujours valide." << std::endl;

//     ptr.reset();

//     return 0;
// }

// Exercice 19 : Comparaison entre Pointeurs et Références

// #include <iostream>

// int increment_ref(int &x)
// {
//     return x++;
// }

// int increment_ptr(int *x)
// {
//     if (x != nullptr)
//     {
//         return (*x)++;
//     }
//     else
//     {
//         std::cout << "x is nullptr" << std::endl;
//         return 1;
//     }
// }

// int main()
// {
//     int a = 5;
//     int b = 10;

//     // std::cout << "Avant incrementation avec référence : " << a << std::endl;
//     // increment_ref(a);
//     // std::cout << "Après incrementation avec référence : " << a << std::endl;

//     std::cout << "Avant incrementation avec pointeur : " << b << std::endl;
//     increment_ptr(&b);
//     std::cout << "Après incrementation avec pointeur : " << b << std::endl;

//     // Exemple avec pointeur nul
//     int *ptr = nullptr;
//     increment_ptr(ptr);
//     return 0;
// }

// Exercice 20 : Déréférencement d'un Pointeur Null
// #include <iostream>

// int main()
// {
//     int *ptr = nullptr;

//     std::cout << "Tentative de déréférencement d'un pointeur nul..." << std::endl;

//     if (ptr != nullptr)
//     {
//         std::cout << "Valeur pointée par ptr : " << *ptr << std::endl;
//     }
//     else
//     {
//         std::cout << "Erreur : le pointeur est nul. Pas de déréférencement possible." << std::endl;
//     }

//     return 0;
// }
