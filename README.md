# HWID Grabber!
You can get hwid serialnumbers of computers with this library!

# How it work?
It works with Windows WMIC app. So, you can use all serialnumber types of WMIC!

# Example Using

```cpp
#include "hwid.h"

int main()
{
  std::cout << getHwid("baseboard");
}
```
