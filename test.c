#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void* Memmove(void* dest, const void* src, size_t num) {
	assert(dest != NULL);
	assert(src != NULL);
	const char* psrc = (const char*)src;
	char* pdest = (char*)dest;
	if (pdest<psrc || pdest>psrc + num) {//判断是否存在内存重叠情况
		for (size_t i = 0; i < num; ++i) {
			pdest[i] = psrc[i];
		}
	}
	else {
		for (size_t i = num; i > 0; --i) {
			pdest[i] = psrc[i];
		}
	}
	return dest;
}
int main() {
	char str[] = "memmove can be very useful......";
	Memmove(str + 20, str + 15, 11);
	puts(str);
	system("pause");
	return 0;
}

