//
// Created by shoshi on 6/1/20.
//

#ifndef DNA_DnaSeq_H
#define DNA_DnaSeq_H


#include <string>
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>


#include "Nucleotide.h"
#include "idna.h"


char getDnaAsStr(Nucleotide n);


class DnaSeq: public IDna
{
public:

    DnaSeq(const std::string&);

    DnaSeq(const DnaSeq&);

    ~DnaSeq();

    DnaSeq& operator=(const DnaSeq&);

    DnaSeq& operator=(const std::string&);

    const Nucleotide& operator[](size_t) const;

    Nucleotide& operator[](size_t);

    size_t len() const;

    const Nucleotide* getDna() const;

//    std::string getDnaAsStr() const;

    inline DnaSeq slicing(size_t start, size_t end) const;

    DnaSeq pair() const;

    size_t find(const DnaSeq& sub, size_t = 0) const;

    size_t count(const DnaSeq& sub) const;

    std::vector<size_t> findAll(const DnaSeq& sub) const;

    std::vector<DnaSeq> findConsensus() const;



private:

    void initStr(const std::string&);

    void initDna(const DnaSeq&);

    Nucleotide* strToDna(std::string);

    Nucleotide* m_dna;

    size_t m_length;
};



inline DnaSeq::DnaSeq(const std::string& dna) : m_dna(NULL), m_length(0) { initStr(dna); }

inline DnaSeq::DnaSeq(const DnaSeq& dna) : m_dna(NULL), m_length(0) { initDna(dna); }

inline DnaSeq::~DnaSeq() { delete[] m_dna; }

inline void DnaSeq::initStr(const std::string& s)
{
    Nucleotide* tmp = strToDna(s);
    delete[] m_dna;
    m_dna = tmp;
    m_length= s.length();
}

inline void DnaSeq::initDna(const DnaSeq& s)
{
    size_t l = s.len();
    Nucleotide* tmp = new Nucleotide[l];
    delete[] m_dna;
    m_dna = tmp;

    for (size_t i = 0; i < l; ++i)
    {
        m_dna[i] = s[i];
    }

    m_length= l;
}

inline DnaSeq& DnaSeq::operator=(const DnaSeq& dna)
{
    initDna(dna);
    return *this;
}

inline DnaSeq& DnaSeq::operator=(const std::string& dna)
{
    initStr(dna);
    return *this;
}

inline Nucleotide& DnaSeq::operator[](size_t i)
{
    if (i >= m_length)
        throw std::overflow_error("out of range.");
    return m_dna[i];
}

inline const Nucleotide& DnaSeq::operator[](size_t i) const
{
    if (i >=m_length)
        throw std::overflow_error("out of range.");
    return m_dna[i];
}


inline size_t DnaSeq::len() const
{
    return m_length;
}

inline const Nucleotide* DnaSeq::getDna() const { return m_dna; }

bool operator==(const DnaSeq&, const DnaSeq&);

bool operator!=(const DnaSeq&, const DnaSeq&);

inline bool operator==(const DnaSeq& d1, const DnaSeq& d2)
{
    size_t l = d1.len();
    if (l != d2.len())
        return 0;

    for (size_t i = 0; i < l; ++i)
    {
        if (d1[i] != d2[i])
            return 0;
    }
    return 1;
}

inline bool operator!=(const DnaSeq& d1, const DnaSeq& d2)
{
    return !(d1.getDna() == d2.getDna());
}


inline std::ostream& operator<<(std::ostream& os, const DnaSeq& d)
{
    for (size_t i = 0; i < d.len(); ++i) {
        os << getDnaAsStr(d[i]);
    }

    return os;
}

DnaSeq dnaFromFile(const char* filename);

std::basic_ofstream<char> fileFromDna(const DnaSeq& d, const char* fileName);

inline DnaSeq DnaSeq::slicing(size_t start, size_t end) const
{
    if(start > end || end > len())
        throw std::out_of_range("Your range is incorrect.");
    std::string myDna, s = "";

    for (size_t j = 0; j < len(); ++j)
    {
        myDna += getDnaAsStr(operator[](j));
    }

    for (size_t i = start; i < end; ++i)
    {
        s += myDna[i];
    }

    return DnaSeq(s);
}



#endif //DNA_DnaSeq_H