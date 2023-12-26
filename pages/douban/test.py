from jinja2 import Template

# 创建模板对象
template = Template(open('template.html').read())

# 定义动态数据
data = {
    'title': 'Welcome to My Website',
    'heading': 'Hello, World!',
    'paragraph': 'This is a paragraph.'
}

# 渲染模板并输出结果
output = template.render(data)
print(output)