# javers
Allows you to set a different default version of the java sdk / runtime by relinking the /usr/lib/jvm/default and default-runtime symlinks to the version you select.

```
em ~/repos/javers $ readlink -f `which java`
/usr/lib/jvm/java-26-openjdk/bin/java
em ~/repos/javers $ sudo javers
Select the version to set:
1. java-26-openjdk
2. java-21-openjdk
3. java-8-openjdk
2
/usr/lib/jvm/java-21-openjdk
em ~/repos/javers $ readlink -f `which java`
/usr/lib/jvm/java-21-openjdk/bin/java
```
