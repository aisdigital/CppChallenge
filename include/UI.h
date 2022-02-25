#pragma once

#include <string>
#include <list>

using std::string;
using std::list;

class UI
{
    public:
        /**
         * @brief Show an error message to the user.
         * 
         * @param error Message to be shown.
         */
        void showError(string error);

        /**
         * @brief Show a message to the user.
         * 
         * @param message Message to be shown.
         */
        void showMessage(string message);

        /**
         * @brief Get user option among available options.
         * 
         * @param options Available options for user.
         * 
         * @return Index of option selected by user.
         */
        int getUserOption(list<string> options);

        /**
         * @brief Get string from user interaction.
         * 
         * @return String entered by user.
         */
        string getUserString();

        /**
         * @brief Resets screen displayed to user.
         */
        void reset();

        /**
         * @brief Wait for user interaction to continue.
         */
        void waitUser();
};