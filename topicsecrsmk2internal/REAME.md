# Topics Repo 


## Contents
   [Description](#description)<br>
   [Building](#building)<br>
   [Testing](#testing)<br>
   [Support](#support)<br>
   [Pull requests](#pull)<br>


<a name=description></a>
## Description

This repo holds the Topics for the ECRS MK2 product. It consists of several .h files arranged into the Topics folder. 

Files in the Topics folder are used to send information between Components.

<a name=building></a>
## Building

The CMake in this repo assumes that the LCA will be checked out at the same level as this repo. Please ensure when you submodule this repo that the LCA repo is at the same level (i.e. the "topics" and "lca" folders are in the same parent folder)

<a name=testing></a>
## Testing

The Topics.cpp file includes every .h file in the Topics folder. It's used for sanity checking that the Topics can be constructed.

When you create a new topic (or delete one) you should update this file.

__This is manual process__

<a name=support></a>
## Support

This repo will be used and supported by both Team Vantage and the RRA team

<a name=pull></a>
## Pull requests

__Teams must not merge in their own Pull Requests__

Teams may review their own changes but the final merge must be done by another team (to avoid any downstream impacts in other repos).

For example:

If a Pull Request is created by Team Vantage, then RRA must merge it (and vice versa).

