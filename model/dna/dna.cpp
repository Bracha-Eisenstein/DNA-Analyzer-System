//
// Created by shoshi on 6/1/20.
//

#include <algorithm>

#include "dna.h"
#include "../../controller/errors/invalid_dna.h"


Nucleotide* DnaSeq::strToDna(std::string s)
{
    if (s.find_first_not_of("ACGTacgt") != std::string::npos)
        throw InvalidDna();
    size_t len = s.length();
    Nucleotide* dna = new Nucleotide[len];

    for (size_t i = 0; i < len; i++)
    {
        if (s[i] == 'A' || s[i] == 'a')
            dna[i] = A;

        else if (s[i] == 'C' || s[i] == 'c')
            dna[i] = C;

        else if (s[i] == 'G' || s[i] == 'g')
            dna[i] = G;

        else if (s[i] == 'T' || s[i] == 't')
            dna[i] = T;
    }
    return dna;
}

char getDnaAsStr(Nucleotide n)
{
    switch (n)
    {
        case A:
            return 'A';

        case C:
            return 'C';

        case G:
            return 'G';

        case T:
            return 'T';
    }

    return 'x';
}

//DnaSeq dnaFromFile(const char* filename)
//{
//    std::ifstream fin;
//    fin.open(filename);
//
//    if(fin.is_open())
//    {
//        std::string line;
//        getline(fin, line);
//        fin.close();
//        DnaSeq dna(line);
//        return dna;
//    }
//    else throw std::domain_error("We couldnt open the file.");
//
//}

std::basic_ofstream<char> fileFromDna(const DnaSeq& d, const char* fileName)
{
    std::ofstream myfile;
    myfile.open(fileName);

    for (size_t i = 0; i < d.len(); ++i)
    {
        myfile << getDnaAsStr(d[i]) <<"\n";
    }

    myfile.close();

    return myfile;
}

DnaSeq DnaSeq::pair() const
{
    std::string s = "" ;
    const Nucleotide* first = getDna();
    size_t l = len();
    for (size_t i = 0; i < l; ++i)
    {
        switch (first[i])
        {
            case A:
                s += "C";
                break;

            case C:
                s += "A";
                break;

            case G:
                s += "T";
                break;

            case T:
                s += "G";
                break;
        }
    }
    std::reverse(s.begin(), s.end());

    return DnaSeq(s);
}

size_t DnaSeq::find(const DnaSeq& sub, size_t start) const
{
    size_t j = 0;
    size_t lSeq = len(), lSub = sub.len();

    for (size_t i = start; i < lSeq - lSub + 1; ++i)
    {
        for (; j < lSub && i + j < m_length; ++j)
        {
            if(m_dna[i + j] != sub[j])
                break;
        }

        if(lSub == j)
            return i;
    }

    return std::string::npos;
}

size_t DnaSeq::count(const DnaSeq& sub) const
{
    size_t res = 0;
    size_t i = find(sub, 0);

    while(i != std::string::npos)
    {
        i = find(sub, i + 1);
        res += 1;
    }

    return res;
}

std::vector<size_t> DnaSeq::findAll(const DnaSeq& sub) const
{
    std::vector<size_t> res;
    size_t i = find(sub, 0);

    while ( i != std::string::npos )
    {
        res.push_back(i);
        i = find(sub, i + 1);
    }

    return res;
}

std::vector<DnaSeq> DnaSeq::findConsensus() const
{
    std::vector<size_t> start = findAll(DnaSeq("ATG"));
    std::vector<size_t> end = findAll(DnaSeq("TAG"));
    std::vector<size_t> end2 = findAll(DnaSeq("TAA")),  end3 = findAll(DnaSeq("TGA"));
    std::vector<DnaSeq> res;
    end.insert(end.end(), end2.begin(), end2.end());

    for (size_t i = 0; i < start.size(); ++i)
    {
        for (size_t j = 0; j < end.size(); ++j)
        {
            if(start[i] < end[j] && (start[i] - end[j]) % 3 == 0)
                res.push_back(slicing(start[i], end[j] + 2));
        }

    }

    return res;
}