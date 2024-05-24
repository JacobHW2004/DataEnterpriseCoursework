#ifndef BANK_DEG_H
#define BANK_DEG_H

namespace Topics {

struct Bank_deg
{
   //deg - degree
   double bank_deg{0};
   bool isValid{false};
   
   Bank_deg() {};

   template <class T>
   void Serialise(T& archive) {
      archive.Serialise(bank_deg, "bank_deg");
      archive.Serialise(isValid, "isValid");
  }

   LCA_TOPIC("Bank_deg", 1, 0)
   

};

}  // namespace Topics

#endif