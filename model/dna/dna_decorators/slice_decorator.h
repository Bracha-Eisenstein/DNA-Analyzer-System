//
// Created by sari on 9/15/20.
//

#ifndef DNA_SLICE_DECORATOR_H
#define DNA_SLICE_DECORATOR_H
#include "../idna.h"
#include "../../../SharedPtr.h"
class SliceDecorator : public IDna
{
public:
    SliceDecorator(shared_ptr<IDna> dnaPtr, size_t start,size_t end);
    size_t len() const;
    const Nucleotide& operator[](size_t) const;
    Nucleotide& operator[](size_t);
private:
    shared_ptr<IDna> m_dna;
    size_t m_start;
    size_t m_end;

};

inline SliceDecorator:: SliceDecorator(shared_ptr<IDna> dnaPtr, size_t start,size_t end): m_dna(dnaPtr), m_start(start),m_end(end){}

#endif //DNA_SLICE_DECORATOR_H
