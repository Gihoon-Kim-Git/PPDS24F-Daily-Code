uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i=0; i < 32; ++i) {
        uint32_t resi = n & 1;
        result += resi << (31-i);
        n = (n >> 1);
    }
    return result;
}