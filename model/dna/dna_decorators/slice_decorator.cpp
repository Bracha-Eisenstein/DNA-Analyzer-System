//
// Created by sari on 9/15/20.
//

#include "slice_decorator.h"
#include <iostream>
size_t SliceDecorator::len() const
{
    return m_end - m_start;
}

const Nucleotide & SliceDecorator::operator[](size_t i) const
{
    return (*m_dna)[m_start + i];
}

Nucleotide & SliceDecorator::operator[](size_t i)
{
    return (*m_dna)[m_start + i];
}