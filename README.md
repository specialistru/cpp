# Курс программирование на С++
- Тема 1: Типы данных, операции и функции в С++. Инкапсуляция.
- Тема 2: Специальные методы класса. Константные и статические члены класса.
- Тема 3: Перегрузка операций. Потоки данных в С++.
- Тема 4: Наследование и полиморфизм. Шаблоны функций и классов.
- Тема 5: Управление исключениями.

# Дополнительные материалы
- IDE Dev-C++ Files​ 5.11​ https://sourceforge.net/projects/orwelldevcpp/files/latest/download
- GCC 15.1 https://github.com/skeeto/w64devkit/releases
- Справочник по языку С++​ ​ https://en.cppreference.com/w/
- Стандарты C и стандарты C++​ https://gcc.gnu.org/projects/cxx-status.html
- GCC Releases​ https://gcc.gnu.org/releases.html
- Build status for GCC​ https://gcc.gnu.org/buildstat.html

# Вспомогательные материалы

PowerShell-скрипт, который перекодирует все .h и .cpp файлы в UTF-8

```bash

$files = Get-ChildItem -Include *.h, *.cpp -Recurse -File;

foreach ($file in $files) {
	$content = [System.IO.File]::ReadAllText($file.FullName, [System.Text.Encoding]::GetEncoding("ISO-8859-1")); 
	[System.IO.File]::WriteAllText($file.FullName, $content, [System.Text.Encoding]::UTF8)
}

```
