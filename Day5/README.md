在C++中，可以通过以下几种方法将数字转换为`std::string`类型：

---

### **1. 使用 `std::to_string` 函数**
`std::to_string` 是 C++11 引入的一个标准函数，用于将数字类型（如 `int`、`float`、`double` 等）转换为字符串。

```cpp
#include <iostream>
#include <string>

int main() {
    int num = 42;
    double pi = 3.14159;

    std::string numStr = std::to_string(num);
    std::string piStr = std::to_string(pi);

    std::cout << "Integer as string: " << numStr << std::endl;
    std::cout << "Double as string: " << piStr << std::endl;

    return 0;
}
```

> **优点**：简单明了，支持多种数值类型。

---

### **2. 使用 `std::ostringstream`**
`std::ostringstream` 是标准库中的流类，可以用于格式化和转换数据类型为字符串。

```cpp
#include <iostream>
#include <sstream>

int main() {
    int num = 42;
    double pi = 3.14159;

    std::ostringstream oss;
    oss << num;
    std::string numStr = oss.str();

    oss.str("");  // 清空流
    oss.clear();  // 重置状态
    oss << pi;
    std::string piStr = oss.str();

    std::cout << "Integer as string: " << numStr << std::endl;
    std::cout << "Double as string: " << piStr << std::endl;

    return 0;
}
```

> **优点**：支持格式化操作，适合复杂的字符串拼接场景。

---

### **3. 使用 `sprintf` 或 `snprintf`**
这是 C 风格的方法，用于将数字格式化为字符串，适合需要特定格式的场景。

```cpp
#include <iostream>
#include <cstdio>

int main() {
    int num = 42;
    double pi = 3.14159;

    char buffer[50];

    // 将整数转换为字符串
    sprintf(buffer, "%d", num);
    std::string numStr(buffer);

    // 将浮点数转换为字符串
    sprintf(buffer, "%.2f", pi);  // 保留两位小数
    std::string piStr(buffer);

    std::cout << "Integer as string: " << numStr << std::endl;
    std::cout << "Double as string: " << piStr << std::endl;

    return 0;
}
```

> **优点**：可以精确控制输出格式。
> **缺点**：使用 C 风格字符串，不够现代化，容易发生缓冲区溢出问题。

---

### **4. 使用 C++20 的 `std::format`**
C++20 引入了 `std::format`，类似于 Python 的格式化字符串功能。

```cpp
#include <iostream>
#include <format>

int main() {
    int num = 42;
    double pi = 3.14159;

    std::string numStr = std::format("{}", num);
    std::string piStr = std::format("{:.2f}", pi);  // 保留两位小数

    std::cout << "Integer as string: " << numStr << std::endl;
    std::cout << "Double as string: " << piStr << std::endl;

    return 0;
}
```

> **优点**：现代化，语法简洁，支持复杂格式。
> **缺点**：需要编译器支持 C++20。

---

### **总结**
- **简单转换**：推荐使用 `std::to_string`。
- **需要格式化**：推荐使用 `std::ostringstream` 或 `std::format`。
- **兼容旧代码**：可以使用 `sprintf`。

根据具体需求和项目要求选择合适的方法。