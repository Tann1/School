
#include <stdio.h>

typedef struct {
  float f1;
  char c1;
  float f2;
  char c2;
} __attribute__((packed)) my_s;

/*
my own conclusion.
Just knowing the fact that floats take 4bytes (32-bits) and char type
take 1byte (8bits) of space in memory; theoretically, my_s struct needs
an ideal allocation of 10 bytes. However, this is not the case as the output
gives us a consistent 4byte allocation for each variable (attribute) declared
in our struct.

An example below (note that i'm only including the least 12-bits (on a 64-bit system) in hex format)

0xb70 -> f1
0xb74 -> c1
0xb78 -> f1
0xb7c -> c2

The above is the ouput when the packed attribute is commented.
Note the excess padding being added to type(s) such as chars. If I had to apply
my knowledge, without looking up a textbook explanation, I'd say that 4bytes is the natural
way to allocate space in memory. The reason being that 4 falls as a result of power of 2 which is
2^2. This would mean that in theory we could ignore the least 2 significant bits when it comes to accessing
variables in memory. Since we know that all variables are consistently 4bytes apart regardless of their types
it allows for an exploitation of bit manipulation. Doing so would actually increase the range of memory access by
4 times the regular amount. since the 32-bit register or 64-bit register no longer addressing individual bytes but rather
a small chuck of memory due to the design choice of previous engineers. 

Now when we uncomment the packed attribute it will implement our theory and gives the ten bytes
we're expecting it to have. A sample output would look something like

(again only showing the least 12-bits in hex format)

0x3fe -> f1
0x402 -> c1
0x403 -> f2
0x407 -> c2

Here note that the allocated space is 10bytes instead of 16bytes which is what we expect.
Though now there may be a slight inconvenience from accessing the memory space but in return
we have optimized our space efficiency. This is a possible opportunity cost. A small price to pay
for this particular program but relevant in actual production. Again whether to use packed is rather a case to case
deicision because it'd really depend on what's the cost of packing everything so tightly versus
access time. Especially when space isn't a primary concern. That's my conclusion of the differences and what I think.
*/


int main(void) {

    my_s s;

    printf("Size: %ld bytes\n"
           "floats %p %p\n"
           "chars %p %p\n",
           sizeof(s), &s.f1, &s.f2, &s.c1, &s.c2);
    return 0;
}