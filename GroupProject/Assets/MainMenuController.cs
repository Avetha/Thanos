﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class MainMenuController : MonoBehaviour
{
    public GameObject mainMenu;
    public GameObject optionsMenu;

    public void playGame()
    {
        SceneManager.LoadScene("Board");
    }

    public void options()
    {
        mainMenu.SetActive(false);
        optionsMenu.SetActive(true);
    }

    public void ScreenMode()
    {
        Screen.fullScreen = !Screen.fullScreen;
    }

    public void exitGame()
    {
        Application.Quit();
    }
}