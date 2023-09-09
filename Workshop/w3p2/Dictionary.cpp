#include "Dictionary.h"

namespace sdds {
    Dictionary::Dictionary() {
    }

    void Dictionary::set(const std::string& term, const std::string& def) {
        m_term = term;
        m_definition = def;
    }
    std::ostream& Dictionary::display(std::ostream& ostr) const {
        ostr << std::right << std::setw(20) << m_term << ": " << m_definition;
        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Dictionary& dict) {
        return dict.display(ostr);
    }

    bool Dictionary::operator==(const Dictionary& dict) const {
        return m_term == dict.m_term && m_definition == dict.m_definition;
    }
}