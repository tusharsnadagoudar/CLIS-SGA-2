# Question 5 - Recovery Mechanisms in vi

## Scenario

Suppose a developer is editing an important configuration file in `vi` and the system suddenly crashes before the file is saved. In this situation, different recovery methods can be used to recover the work and reduce data loss.

## Recovery Mechanisms

### 1. Swap Files

While editing a file, `vi`/`vim` can create a swap file that stores recovery information. If the system crashes, the swap file may contain the unsaved changes.

Recovery can be attempted using:

`vi -r filename`

This is one of the most useful methods for recovering recent unsaved work after a crash.

### 2. Undo History

Undo history keeps track of changes made while editing. It helps us go back to an earlier state of the file.

However, after a system crash, the undo history may not always be available unless persistent undo was already enabled.

### 3. Registers

Registers store text that has been copied, deleted, or changed during editing. They can help recover recently edited text during an active session.

After a complete system crash, registers are less reliable because their contents may not be available.

### 4. Backup Files

Backup files contain an earlier saved copy of the original file. If recovery of the latest changes is not possible, a backup can be used to restore the previous version.

The disadvantage is that the backup may not contain changes made just before the crash.

### 5. Auto-Recovery

`vi`/`vim` can use available recovery information after an unexpected crash to help restore an interrupted editing session.

After recovering the file, we should check the contents carefully before saving it so that a correct existing file is not accidentally overwritten.

## Most Reliable Recovery Strategy

The best approach is to first keep the original file and any available recovery files safe. Then try to recover the latest unsaved changes using the swap file or available recovery information.

After recovery, the file should be compared with the last saved or backup version. If the recovered content is correct, it can then be saved safely.

Using swap-file recovery along with a backup is more reliable because the swap file can help recover recent unsaved changes, while the backup provides an older safe copy if recovery fails.

## Conclusion

Swap files and auto-recovery are useful after an unexpected crash, while backup files provide an additional safe copy. Undo history and registers can also help when their data is still available.

For an important configuration file, using recovery information first and keeping a backup as a fallback is the safest recovery strategy.
