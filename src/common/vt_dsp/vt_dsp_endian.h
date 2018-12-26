#pragma once

#define vt_read_int32LE vt_write_int32LE
#define vt_read_int32BE vt_write_int32BE
#define vt_read_int16LE vt_write_int16LE
#define vt_read_int16BE vt_write_int16BE
#define vt_read_float32LE vt_write_float32LE

inline int vt_write_int32LE(int t)
{
   return t;
}

inline float vt_write_float32LE(float f)
{
   return f;
}

inline int vt_write_int32BE(int t)
{
#if (__linux__ || MAC || _M_X64)
   return __builtin_bswap32(t);
#else
   return _byteswap_ulong(t);
#endif
}

inline short vt_write_int16LE(short t)
{
   return t;
}

inline short vt_write_int16BE(short t)
{
   return ((t << 8) & 0xff00) | ((t >> 8) & 0x00ff);
}

inline void vt_copyblock_W_LE(short* dst, const short* src, size_t count)
{
   memcpy(dst, src, count * sizeof(short));
}

inline void vt_copyblock_DW_LE(int* dst, const int* src, size_t count)
{
   memcpy(dst, src, count * sizeof(int));
}
