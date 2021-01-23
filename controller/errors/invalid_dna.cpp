#include "invalid_dna.h"
const char* InvalidDna::what()
{
    return "You're DNA is invalid.\ncorrect DNA contain only the letters: A, T, C or G.\ntry again.";
}
