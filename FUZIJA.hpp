#ifndef FUZIJA_HPP_INCLUDED
#define FUZIJA_HPP_INCLUDED

// Genericka funkcija za fuziju nizova objekata.

template <typename T>
  void fuzija(const T* a, int na, const T* b, int nb, T*& c, int& nc) {
    c = new T [nc=na+nb];
    int ia=0, ib=0, ic=0;
    while (ia<na || ib<nb)
      c[ic++] = ia==na      ? b[ib++] :
                ib==nb      ? a[ia++] :
                a[ia]<b[ib] ? a[ia++] : b[ib++];
  }

#endif // FUZIJA_HPP_INCLUDED
