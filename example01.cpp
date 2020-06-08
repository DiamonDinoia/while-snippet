
#include <random>

int main(int argc, char *argv[]) {

  std::default_random_engine first_generator(time(nullptr));
  std::default_random_engine second_generator(time(nullptr));

  std::uniform_real_distribution<double> first_distribution(0.0, 1.0);
  std::uniform_real_distribution<double> second_distribution(0.0, 1.0);
  for (auto i = 0; i < 1024; ++i) {
    do {
      const auto first_random = first_distribution(first_generator);
      const auto second_random = second_distribution(first_generator);
      if (first_random < second_random)
        break;
    } while (true);
  }
}