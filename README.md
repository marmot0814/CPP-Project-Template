CPP-Project-Template
---
## Build and Test
To build and test the CPP project, follow these steps:
```
cmake -B build \
  -DCMAKE_BUILD_TYPE=Debug .
make -C build -j
make test -C build
```

## CI/CD Setup
To configure Continuous Integration/Continuous Deployment (CI/CD) for your project, follow these instructions:
1. `Settings` > `Secrets and variables` > `Actions`
2. Click `New repository secret` and add following variables
  - `DEPLOY_HOST`: remote server domain name
  - `DEPLOY_USER`: remote server uploader username
  - `DEPLOY_WORK_DIR`: remote server deploy path
  - `DEPLOY_PRIVATE_KEY`: content of the private key

## Workflow
### Development
1. Create a new branch using the command:
```
git checkout -b <branch name>
```
2. After completing the changes, create a pull request into master. CI will generate a preview and provide a link within the pull request for review.
3. Once confirmed, merge the pull request into master. CI will also update the results for this version simultaneously.

### Release Specific Version
To deploy a specific version of your project, follow these steps:
```
git tag <tag-name>
git push origin <tag-name>
```
Once the tag is pushed, your project will be deployed at: `https://<DEPLOY_HOST>/<REPO_NAME>/tag/<tag-name>`.
