# ShutterSort 
<img src="https://github.com/m-riley04/ShutterSort/blob/main/assets/ShutterSort%20Logo%20DRAFT.png" width="128"/>
A team project for EECS 348 - Software Development I at the University of Kansas.

# Table of Contents
* [Description](#Description)
* [Functionality](#Functionality)
  * [Planned Functionality](#Planned-Functionality)
* [Installation](#Installation)
* [Building](#Building)
  * [Dependencies](#Dependencies)
* [The Team](#The-Team)
  * [Members](#Members)
  * [Meetings](#Meetings)
  * [Artifacts](#Artifacts)

# Description
A photo sorting software that uses cutting edge technology, machine learning, and more to efficiently, effectively, and easily sort images for photographers and average users alike! For the terminology when reading this README, please refer to our [Wiki](https://github.com/m-riley04/ShutterSort/wiki).

# Functionality
* Over 100 different sorting methods for image metadata (powered by [Exiv2](https://exiv2.org/))
  * Brightness
  * Lens Model
  * Rating
  * Etc...
* Error-checking and file protection
* "Anchor"-based image uploading
* Stopping and starting of sorting
* Automatic, multi-threaded processing

## Planned Functionality
* Machine-learning image detection sorting methods
* Multiple Anchor points
* GUI for Anchor point management and movement

# Installation
1. Navigate to the [Releases](https://github.com/m-riley04/ShutterSort/releases) section on the GitHub page
2. Find the latest release
3. Click and download "ShutterSort.zip"
4. Extract the zipped folder
5. Run the .exe file within the extracted folder

# Usage
1. Open the app
2. Put in the desired Anchor point path (directory path) into the text field
3. Put in the desired output folder for the sorted images
4. Press "Start sorting"!

# Building and Testing
To build and run the source code, it is recommended that you use QtCreator 12.0.0. You can download the Qt framework and QtCreator [here](https://www.qt.io/download).

## Dependencies
Dependencies are managed using [vcpkg](https://vcpkg.io). You must configure your VCPKG path in the CMAKE file. You must also install the "vcpkg" addon/plugin for QtCreator.
* Exiv2

# The Team
_**CRRANkS**_
## Members
* **Riley Meyerkorth**   - Team Administrator
* **Sam Aven**           - Lead Developer
* **Alex Doehring**      - QA Lead
* **Nicholas Holmes**    - Creative Director
* **Ryland Edwards**     - Front-End Lead
* **Colin Treanor**      - Documentation Technician

## Meetings
Meetings, agendas, and logs can be found in the project [Wiki](https://github.com/m-riley04/ShutterSort/wiki).

## Artifacts
Most if not all of the required artifacts for the project (Project Management Plan, SRS, etc.) can be found within the "documentation" folder [here](https://github.com/m-riley04/ShutterSort/tree/main/documentation).
