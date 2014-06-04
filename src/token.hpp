#ifndef LASKIN_TOKEN_HPP_GUARD
#define LASKIN_TOKEN_HPP_GUARD

#include <iostream>

namespace laskin
{
    class token
    {
    public:
        enum type
        {
            type_lparen,
            type_rparen,
            type_lbrack,
            type_rbrack,
            type_lbrace,
            type_rbrace,
            type_colon,
            type_int,
            type_real,
            type_ratio,
            type_string,
            type_word,
            type_kw_if,
            type_kw_else,
            type_kw_for,
            type_kw_case,
            type_kw_while,
            type_kw_to
        };

        /**
         * Constructs new token.
         *
         * \param type Type of the token
         * \param data Text data associated with the token
         */
        explicit token(enum type type = type_word,
                       const std::string& data = std::string());

        /**
         * Copy constructor.
         */
        token(const token& that);

        /**
         * Returns type of the token.
         */
        inline enum type type() const
        {
            return m_type;
        }

        /**
         * Tests whether token is given type.
         */
        inline bool is(enum type type) const
        {
            return m_type == type;
        }

        /**
         * Returns text data associated with the token.
         */
        inline const std::string& data() const
        {
            return m_data;
        }

        bool equals(const token& that) const;

        /**
         * Equality testing operator.
         */
        inline bool operator==(const token& that) const
        {
            return equals(that);
        }

        /**
         * Non-equality testing operator.
         */
        inline bool operator!=(const token& that) const
        {
            return !equals(that);
        }

        /**
         * Copies contents from another token into this one.
         */
        token& assign(const token& that);

        /**
         * Assignment operator.
         */
        inline token& operator=(const token& that)
        {
            return assign(that);
        }

    private:
        /** Type of the token. */
        enum type m_type;
        /** Text data associated with token. */
        std::string m_data;
    };

    std::ostream& operator<<(std::ostream&, const token&);
    std::ostream& operator<<(std::ostream&, enum token::type);
}

#endif /* !LASKIN_TOKEN_HPP_GUARD */
