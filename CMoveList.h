#ifndef _C_MOVELIST_H_
#define _C_MOVELIST_H_

#include <iostream>
#include <vector>

#include "CMove.h"

/***************************************************************
 * declaration of CMoveList
 *
 * This is a wrapper for the std::vector class.
 * It contains an array of moves.
 ***************************************************************/

class CMoveList
{
    public:
        CMoveList()
            : m_moveList()
        {
            // Pre-allocate space for a large number of moves.
            // This is a slight optimization.
            m_moveList.reserve(100);
        }

        friend std::ostream& operator <<(std::ostream &os, const CMoveList &rhs);

        std::string ToShortString() const;

        std::string ToLongString() const;

        bool is_in(const CMove& move) const
        {
            for (std::vector<CMove>::const_iterator it = m_moveList.begin(); it != m_moveList.end(); ++it)
            {
                if ((*it) == move)
                    return true;
            }
            return false;
        }

        void push_back(const CMove& move)
        {
            m_moveList.push_back(move);
        }

        void insert_front(const CMove& move)
        {
            m_moveList.insert(m_moveList.begin(), move);
        }

        CMoveList& operator += (const CMoveList& rhs)
        {
            m_moveList.insert(m_moveList.end(), rhs.m_moveList.begin(), rhs.m_moveList.end());
            return *this;
        }

        CMoveList& operator = (const CMove& move)
        {
            m_moveList.clear();
            m_moveList.push_back(move);
            return *this;
        }

        CMove last() const
        {
            unsigned int size = m_moveList.size();
            if (size)
            {
                return m_moveList[size-1];
            }
            CMove move;
            return move;
        }

        void pop_back()
        {
            m_moveList.pop_back();
        }

        void clear()
        {
            m_moveList.clear();
        }

        unsigned int size() const
        {
            return m_moveList.size();
        }

        const CMove & operator [] (unsigned int ix) const { return m_moveList[ix]; }

        CMove & operator [] (unsigned int ix) { return m_moveList[ix]; }

    private:
        std::vector<CMove> m_moveList;

}; /* end of CMoveList */

// This is a compile-time check to ensure that we don't use the + operator
// on two CMoveList objects.
CMoveList operator + (const CMoveList& lhs, const CMoveList& rhs);

#endif // _C_MOVELIST_H_

