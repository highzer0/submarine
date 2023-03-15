# Planning options

<aside>
💡 This template documents how to review code. Helpful for new and remote employees to get and stay aligned.

</aside>

# Philosophy

Why do you perform code reviews? What are your guiding principles for these reviews?

You may want to mention other pages here. Like Engineering Guidelines. To link to another page inline, type `@`followed by the name of the page: [Quy tắc làm việc on-site](Quy%20ta%CC%86%CC%81c%20la%CC%80m%20vie%CC%A3%CC%82c%20on-site%20cab743c8f3c34f77a074b6324b422cd0.md) 

# Preparing Code for Review

Preparation sets your reviewers up for success.

### Commit Messages

Make sure your commit messages are descriptive.

### Github PR Descriptions

Your PR descriptions should be an extension of your commit messages. Write about both what the commit changes, and how you implemented the change.

# Performing Code Reviews

### How to Review

- Make two passes over the PR if it's substantial.
    - On the first pass, come to an understanding of the code change at a high level.
    - On the second pass, pay more attention to semantic details.

# Examples

```jsx
var commentCount = 0;

```

You might suggest that this be a `let` instead of `var`.