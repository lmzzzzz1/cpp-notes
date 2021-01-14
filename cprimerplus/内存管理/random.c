static unsigned long int next = 1; // seed

unsigned int rand0(void) {
    next = next * 1103515245 + 12345;
    return (unsigned int)(next/65536) % 32768;
}

void srand0(unsigned int seed) {
    next = seed;
}

