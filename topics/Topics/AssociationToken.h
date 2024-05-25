#ifndef ASSOCIATION_TOKEN_H
#define ASSOCIATION_TOKEN_H

#include <string>
#include "Fabric/Utils/LCA_Macros.h"

namespace Topics {

    class AssociationToken {
    private:

        std::string token{};

    public:

        AssociationToken() = default;

        AssociationToken(const std::string& aToken) :
            token(aToken)
        {}

        const std::string& getToken() const{
            return token;
        }

        template <class T>
        void Serialise(T& archive) {
            archive.Serialise(token, "token");
        }

        LCA_TOPIC("AssociationToken", 1, 0);
    };

}
#endif