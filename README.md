# FlowBuilder

## Description
A simple CLI app that lets you build a flowchart and execute it.

## Test Matrix

| Test Case ID | Description             | Input                                                                                      | Expected Outcome                          | Actual Outcome | Status  |
|--------------|-------------------------|--------------------------------------------------------------------------------------------|-------------------------------------------|----------------|---------|
| TC001        | Add a name for the flow | Name: 'test'                                                                               | File name 'test.flow'                     |                | Pending |
| TC002        | Delete a flow           | Choose 5. Delete Workflows<br/>Enter the number of the flow to delete: 0                   | Flow is not in the library of flows       |                | Pending |
| TC003        | View all flows          | Choose 3. Show Workflows                                                                   | Flows viewable                            |                | Pending |
| TC004        | Add a new flow          | Choose 1. Add Workflow                                                                     | Flow is added                             |                | Pending |
| TC005        | Add a Title step        | Choose 1. Add Workflow<br/>Choose 1. Title                                                 | Title step is added                       |                | Pending |
| TC006        | Flow has a timestamp    | Choose 1. Add Workflow<br/>Choose 10. End                                                  | Flow created successfully.                |                | Pending |
| TC007        | Flow is saved on END    | Choose 1. Add Workflow<br/>Choose 10. End                                                  | Workflow saved successfully.              |                | Pending |
| TC008        | Execute a flow          | Choose 1. Add Workflow<br/>Choose 10. End<br/>Choose 2. Execute                            | Flow is executed                          |                | Pending |
| TC009        | New flow is displayed   | Choose 1. Add Workflow<br/>Choose 10. End<br/> 3.Show Workflows                            | Flow is displayed in the 3 Show Workflows |                | Pending |
| TC010        | Flow is deleted         | Choose 1. Add Workflow<br/>Choose 10. End<br/> 5.Delete Workflows                          | Flow is deleted                           |                | Pending |
| TC011        | Steps are skipped       | Choose 1. Add Workflow<br/>Choose 10. End<br/> 2.Skip Steps                                | Steps are skipped                         |                | Pending |
| TC012        | Quit the flow builder   | Choose 6. Execute Workflow <br/> Press q                                                   | Flow builder is closed                    |                | Pending |
| TC013        | Non-integer input       | Choose 1. Add Workflow<br/>Choose 10. End<br/> 2.Skip Steps                                | Error message is displayed                |                | Pending |
| TC014        | Multiple calculus steps | Choose 1. Add Workflow<br/>Choose Calculus<br/> Add 3 steps                                | No error message                          |                | Pending |
| TC015        | Multiple flow steps     | Choose 1. Add Workflow<br/>Choose Flow<br/> Add 3 steps                                    | No error message                          |                | Pending |
| TC016        | Cancel deletion         | Choose 1. Add Workflow<br/>Choose 5.Delete Workflows <br/> Choose -1                       | Flow is not deleted                       |                | Pending |
| TC017        | Graceful exit           | Choose Exit                                                                                | Flow builder is closed No error message   |                | Pending |
| TC018        | Title with whitespaces  | Choose 1. Add Workflow<br/>Choose 1. Title<br/> Enter 'test test'                          | Title is 'test test'                      |                | Pending |
| TC019        | Output step creates file| Choose 1. Add Workflow<br/>Choose Text_Input<br/> Choose 3. Output                         | File is created                           |                | Pending |
| TC020        | Output step appends     | Choose 1. Add Workflow<br/>Choose Text_Input with the same file name<br/> Choose 3. Output | File is appended                          |                | Pending |

## Demo GIF
Full Demo in the README_assets folder