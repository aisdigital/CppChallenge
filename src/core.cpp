/** Challenge C++ AISDigital
 * Author: Cícero Borba Walendowsky
 * Date of creation: 1646529870
 * src/core.cpp
 **/

// #include <future>
#include <iostream>
// #include <thread>

#include "core.h"
#include "fileRead.h"
#include "fileSave.h"
#include "searchByDbn.h"
#include "searchByName.h"
#include "view.h"

namespace CppChallenge {
namespace Core {

core::core()
    : data_(),
      data_header_(),
      search_result_(),
      file_path_("/home/git/CppChallenge/input/SAT__College_Board__2010_School_Level_Results.csv"),
      end_program_(false),
      view_(new(View::view)),
      file_reader_(new(FileRead::fileRead)) {
    Init();
}

core::~core() {}

void core::Init() {
    if (LoadData()) {
        view_->InfoInit();
        Loop();
    } else {
        view_->InfoNoDataCloseProgram();
    }
}

bool core::LoadData() {
    view_->InfoLoadData();
    // std::future<std::vector<std::vector<std::string>>> load_thread =
    //         std::async(std::launch::async, file_reader_->ReadFile, file_path_);
    // data_ = load_thread.get();
    data_ = file_reader_->ReadFile(file_path_);
    data_header_ = data_[0];
    return static_cast<bool>(data_.size());
}

void core::Loop() {
    bool first_call = true;
    while (!end_program_) {
        if (!first_call) {
            view_->InfoReturnToMainMenu();
        }
        MainMenu();
        first_call = false;
        search_result_.clear();
    }
}

void core::MainMenu() {
    view_->MainMenu();
    MainMenuInput();
}

void core::MainMenuInput() {
    switch (view_->ReadInt()) {
    case 1:
        MenuSearchByName();
        break;
    case 2:
        MenuSearchByDbn();
        break;
    case 3:
        EndProgram();
        break;
    default:
        InvalidOption();
        break;
    }
}

void core::MenuSearchByName() {
    view_->MenuSearchByName();
    DisplayResultsByName();
}

void core::DisplayResultsByName() {
    SearchByName::searchByName name_searcher = SearchByName::searchByName();
    search_result_ = name_searcher.FindName(data_, view_->ReadString());
    if (!search_result_.empty()) {
        view_->PrintResults(data_header_, search_result_);
        MenuAskSaveFile();
    } else {
        view_->InfoNameNotFound();
    }
}

void core::MenuAskSaveFile() {
    view_->MenuAskSaveFile();
    switch (view_->ReadYesNoConfirmation()) {
    case 1:
        MenuSaveFile();
        break;
    case 2:
        view_->InfoFileNotSaved();
        break;
    case 0:
        view_->InfoInvalidAnswer();
        break;
    default:
        break;
    }
}

void core::MenuSaveFile() {
    view_->MenuSaveFile();
    FileSave::fileSave file_saver = FileSave::fileSave();
    bool is_saved = file_saver.SaveFile(search_result_, data_header_, view_->ReadString());
    if (is_saved) {
        view_->InfoFileSaved();
        return;
    } else {
        view_->InfoErrorSavingFile();
        return;
    }
}

void core::MenuSearchByDbn() {
    view_->MenuSearchByDbn();
    DisplayResultsByDbn();
}

void core::DisplayResultsByDbn() {
    SearchByDbn::searchByDbn dbn_searcher = SearchByDbn::searchByDbn();
    std::vector<std::string> dbn_found_output = dbn_searcher.FindDbn(data_, view_->ReadString());
    if (!dbn_found_output.empty()) {
        search_result_.push_back(dbn_found_output);
        view_->PrintResults(data_header_, search_result_);
    } else {
        view_->InfoDbnNotFound();
    }
}

void core::EndProgram() {
    view_->InfoEndProgram();
    end_program_ = true;
}

void core::InvalidOption() {
    view_->InfoInvalidOption();
}

}  // namespace Core
}  // namespace CppChallenge