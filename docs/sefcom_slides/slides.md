% Sefcom/BSS meeting [8/27]
% Source-to-Source Code Transformations 
% 

## Source-to-Source Code Transformations

#### Problem and Hypothesis
- There are many un-repaired bugs that current APR tools can not patch. 

- There is a discrepancy between the granularity of the mutation operation
and the required granularity of the repair.

#### Our Transformation Goals
  - [1] Increase Statement Granularity
  - [2] Add Similarly-Grained Repair Ingredients

## The Transformations (tN)

#### [1] Increasing Statement Granularity 
- Decouple assignment and declaration. (t1)
- Extract the content of function calls. (t2)
- Extract function calls from conditional statements. (t3)

#### [2] Adding Repair Ingredients 
- Get ingredient type,values from comparators and assignments
- Assign casted values to type-compatible local variables (t4)
  * Obtain local variable names from [1]
  * No impact to execution---guaranteed by screening out function calls from values

## Example Transformations [t1--t3]
\footnotesize
```
/* Original buggy code */
if (cgc_receive_delim(0, string, 128, '\n') != 0)
    return -1;
------------------------------------------------
/* After transformations and successful APR */
  int tlv1 ;
...
  tlv3 = 0;
  tlv4 = string;
  tlv5 = sizeof(string); /* (t4) seeded repair | original: tlv5 = 128; */
  tlv6 = (char )'\n';
  tlv1 = cgc_receive_delim(tlv3, tlv4, (cgc_size_t const   )tlv5, tlv6);
  if (tlv1 != 0) {
    return (-1);
  } 
```

## Progress
- Case study: Found a "high quality repair" (i.e. developer-specified) for the CGC challenge binary ***Palindrome***.
- Preparing to run on the entire CGC challenge binary (CB) set.
	- We have identified 6 more CGC CBs that transformations will aid.
	- IDEA: Our method may improve the "quality" of repairs found by APR tools, by identifying more _correct_ repairs.

<!--
## LINE pre letter sealing
:::::::::::::: {.columns}
::: {.column width="50%"}
- Issues?
- Who can read the decrypted message?
- How would you fix this?
:::
::: {.column width="50%"}
![](LINE_unseal.png){ width=80% }
:::
::::::::::::::
--->
