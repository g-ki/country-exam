#include<iostream>
#include<string>
#include<vector>

class Purchase {
  protected:
    std::string name_;
    double unit_price_;
  public:
    Purchase(std::string name, double unit_rice)
      : name_(name), unit_price_(unit_rice) {}

    double virtual value() const = 0;

    std::string name() const { return name_; }

    double unit_rice() const { return unit_price_; }
};

class CountPurchase : public Purchase {
  int count_;
  public:
    CountPurchase(std::string name, double unit_price, int count) :
      Purchase(name, unit_price), count_(count) {}

    double value() const {
      return unit_price_ * count_;
    }

    int count() const { return count_; }
};

class VolumePurchase : public Purchase {
  double volume_;
  public:
    VolumePurchase(std::string name, double unit_price, double volume) :
      Purchase(name, unit_price), volume_(volume) {}

    double value() const {
      return unit_price_ * volume_;
    }

    double volume() const { return volume_; }
};

class Bill {
  int id_;
  std::vector<Purchase*> purchases_;
  public:
    Bill(int id, std::vector<Purchase*> purch_arr) : id_(id), purchases_(purch_arr) {}

    double value() const {
      double sum = 0;
      for (int i = 0; i < purchases_.size(); ++i)
        sum += purchases_[i]->value();

      return sum;
    }

    int id() const { return id_; }
};

int main() {
  CountPurchase cp("Cp 1", 10, 3);
  VolumePurchase vp("Vp 1", 10, 1.5);


  std::vector<Purchase*> bill_vec;
  bill_vec.push_back(&cp);
  bill_vec.push_back(&vp);

  Bill dBill(101, bill_vec);
  std::cout << dBill.value() << std::endl;
}
