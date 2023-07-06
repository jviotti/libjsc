#include <iostream>
#include <JavaScriptCore/JavaScript.h>

int main() {
  JSStringRef string = JSStringCreateWithUTF8CString("Foo");
  JSStringRelease(string);
  std::cout << "JSC\n";
  return 0;
}
