//#include <QApplication>
#include <iostream>
#include <torch/csrc/autograd/variable.h>
#include <torch/torch.h>
#include <zz.h>

using namespace std;

struct Net : torch::nn::Module {
  Net(int64_t N, int64_t M) {
    W = register_parameter("W", torch::randn({N, M}));
    b = register_parameter("b", torch::randn(M));
    c = register_parameter("c", torch::randn(M));
  }

  torch::Tensor forward(torch::Tensor input) {
    return torch::addmm(b, input, W);
  }
  torch::Tensor W, b, c;
};

int main(int argc, char *argv[]) {
  Net net(4, 5);
  for (const auto &p : net.parameters()) {
    std::cout << p << std::endl;
  }

  QApplication app(argc, argv);
  MainWindow w;
  w.show();
  return app.exec();
}
