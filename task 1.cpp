#include <iostream> // Включає стандартну бібліотеку вводу-виводу

using namespace std; // Вказує компілятору на використання простору імен std

// Функція для знаходження індексу максимального елемента масиву
int max_element(int a[], int n) {
  int max_element = a[0]; // Ініціалізуємо максимальний елемент першим елементом масиву
  int max_element_index = 0; // Ініціалізуємо індекс максимального елемента нулем
  for (int i = 1; i < n; i++) { // Проходимо по всіх елементах масиву, починаючи з другого
    if (a[i] > max_element) { // Якщо поточний елемент більший за максимальний
      max_element = a[i]; // Оновлюємо максимальний елемент
      max_element_index = i; // Оновлюємо індекс максимального елемента
    }
  }
  return max_element_index; // Повертаємо індекс максимального елемента
}

// Функція для обчислення добутку ненульових елементів масиву
int product_of_nonzero_elements(int a[], int n) {
  int product = 1; // Ініціалізуємо добуток одиницею
  for (int i = 0; i < n; i++) { // Проходимо по всіх елементах масиву
    if (a[i] != 0) { // Якщо поточний елемент не дорівнює нулю
      product *= a[i]; // Множимо його на добуток
    }
  }
  return product; // Повертаємо добуток
}

// Функція для перестановки елементів масиву
void rearrange_array(int a[], int n) {
  int i = 0; // Ініціалізуємо індекс i нулем
  int j = 1; // Ініціалізуємо індекс j одиницею
  while (i < n && j < n) { // Поки обидва індекси менші за розмір масиву
    if (i % 2 == 0) { // Якщо i - парне число
      int temp = a[i]; // Зберігаємо значення елемента з індексом i в тимчасову змінну
      a[i] = a[j]; // Присвоюємо елементу з індексом i значення елемента з індексом j
      a[j] = temp; // Присвоюємо елементу з індексом j тимчасове значення
    }
    i++; // Збільшуємо i на 1
    j++; // Збільшуємо j на 1
  }
}

// Основна функція програми
int main() {
  int n;
  cout << "Enter the array size: "; // Запитуємо розмір масиву
  cin >> n;
  int a[n];
  cout << "Enter the array elements: "; // Запитуємо елементи масиву
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // Обчислюємо номер максимального елемента масиву
  int max_element_index = max_element(a, n);
  cout << "The index of the maximum element is: " << max_element_index << endl;

  // Обчислюємо добуток елементів масиву, розташованих між першим і другим нульовими елементами
  int product = product_of_nonzero_elements(a, n);
  if (product == 0) {
    cout << "There are no nonzero elements in the array." << endl;
  } else {
    cout << "The product of nonzero elements is: " << product << endl;
  }

  // Переміщуємо елементи масиву
  rearrange_array(a, n);
  cout << "The rearranged array is: "; // Виводимо переставлений масив
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  return 0; // Завершуємо програму з кодом успіху
}
