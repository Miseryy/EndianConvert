#include <string.h>

class EndianConvert {
public:
    template<class T>
    static void Conv(T src, T* dest) {
        T and_mask = 0xff;
        T little = 0;
        while(1) {
            little += (src & and_mask);
            src = src >> 8;
            if(src == 0x00) {
                break;
            }

            little = little << 8;

        }

        *dest = little;

    }

    template<class T>
    static void Conv(T *src, T* dest, int num) {
        T *tmp = new T(num);
        for(int i = num; 0 < i; --i) {
            tmp[i-1] = src[num - i];
        }

        memcpy(dest, tmp, num);
        delete tmp;
    }
};
