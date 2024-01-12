# FlowBuilder

## Description
A simple CLI app that lets you build a flowchart and execute it.

## Test Matrix

| Test Case ID | Description             | Input                                                                                      | Expected Outcome                           | Actual Outcome                                                                      | Status  |
|--------------|-------------------------|--------------------------------------------------------------------------------------------|--------------------------------------------|-------------------------------------------------------------------------------------|---------|
| TC001        | Add a name for the flow | Name: 'test'                                                                               | File name 'test.flow'                      | File 'test.flow' exists                                                             | Pass    |
| TC002        | Delete a flow           | Choose 5. Delete Workflows<br/>Enter the number of the flow to delete: 0                   | Flow is not in the library of flows        | The file is not in the file system                                                  | Pass |
| TC003        | View all flows          | Choose 3. Show Workflows                                                                   | Flows viewable                             | All the files in the current directory that have .flow are shown                    | Pass |
| TC004        | Add a new flow          | Choose 1. Add Workflow                                                                     | Flow is added                              | A new flow is created                                                               | Pass |
| TC005        | Add a Title step        | Choose 1. Add Workflow<br/>Choose 1. Title                                                 | Title step is added                        | The flow contains a title step                                                      | Pass |
| TC006        | Flow has a timestamp    | Choose 1. Add Workflow<br/>Choose 10. End                                                  | Flow created successfully with a timestamp | The .flow file contains a timestamp of the form timestamp: Fri Jan 12 16:28:46 2024 | Pass |
| TC007        | Flow is saved on END    | Choose 1. Add Workflow<br/>Choose 10. End                                                  | Workflow saved successfully.               | Saving Flow to file, Workflow saved successfully                                    | Pass |
| TC008        | Execute a flow          | Choose 1. Add Workflow<br/>Choose 10. End<br/>Choose 2. Execute                            | Flow is executed                           | Menu with skipping the step or not                                                  | Pass |
| TC009        | New flow is displayed   | Choose 1. Add Workflow<br/>Choose 10. End<br/> 3.Show Workflows                            | Flow is displayed in the 3 Show Workflows  | The FSManager contains the new flow                                                 | Pass |
| TC010        | Flow is deleted         | Choose 1. Add Workflow<br/>Choose 10. End<br/> 5.Delete Workflows                          | Flow is deleted                            | The flow is not viewable in the file system                                         | Pass |
| TC011        | Steps are skipped       | Choose 1. Add Workflow<br/>Choose 10. End<br/> 2.Skip Steps                                | Steps are skipped                          | Goes to the next step                                                               | Pass |
| TC012        | Quit the flow builder   | Choose 6. Execute Workflow <br/> Press q                                                   | Flow builder is closed                     | Goes to the main menu                                                               | Pass |
| TC013        | Non-integer input       | Choose 1. Add Workflow<br/>Choose 10. End<br/> 2.Skip Steps                                | Error message is displayed                 | Error with NON INTEGER                                                              | Pass |
| TC014        | Multiple calculus steps | Choose 1. Add Workflow<br/>Choose Calculus<br/> Add 3 steps                                | No error message                           | Added 3 steps                                                                       | Pass |
| TC015        | Multiple flow steps     | Choose 1. Add Workflow<br/>Choose Flow<br/> Add 3 steps                                    | No error message                           | No error after 5 steps                                                              | Pass |
| TC016        | Cancel deletion         | Choose 1. Add Workflow<br/>Choose 5.Delete Workflows <br/> Choose -1                       | Flow is not deleted                        | The flow is still in the file system                                                | Pass |
| TC017        | Graceful exit           | Choose Exit                                                                                | Flow builder is closed No error message    | Exits with code 0                                                                   | Pass |
| TC018        | Title with whitespaces  | Choose 1. Add Workflow<br/>Choose 1. Title<br/> Enter 'test test'                          | Title is 'test test'                       | Title is 'test test'                                                                | Pass |
| TC019        | Output step creates file| Choose 1. Add Workflow<br/>Choose Text_Input<br/> Choose 3. Output                         | File is created                            | Creates a new file                                                                  | Pass |
| TC020        | Output step appends     | Choose 1. Add Workflow<br/>Choose Text_Input with the same file name<br/> Choose 3. Output | File is appended                           | Adds the text to the file provided without changing the previous text               | Pass |

## Demo GIF
Full Demo in the README_assets folder
![Demo](README_assets/output.gif)