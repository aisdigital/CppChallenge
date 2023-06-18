#include "Controller.h"

Controller::Controller(std::unique_ptr<ICSVParser>&& parser,
					   std::unique_ptr<IMenu>&& menu) :
	parser(std::move(parser)), menu(std::move(menu))
{
}

void Controller::run() {
	initialize();

	parseFuture.get();

	int op = menu->printMain();
}

void Controller::initialize() {
	menu->printLoading();
	parseFuture = parser->parse();
}
