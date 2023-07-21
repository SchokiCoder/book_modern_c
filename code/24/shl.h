#ifndef _SHL_H
#define _SHL_H

int
intplusfloat(int a, float b);

#ifdef SHL_IMPL

int
intplusfloat(int a, float b)
{
        return a + (int) b;
}

#endif /* SHL_IMPL */

#endif /* _SHL_H */
